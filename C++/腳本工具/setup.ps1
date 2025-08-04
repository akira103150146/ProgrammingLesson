# Check for Administrator privileges
If (-NOT ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")) {
    Write-Host "[ERROR] Please run this script as Administrator!" -ForegroundColor Red
    Pause
    Exit
}

Write-Host ">>> Checking Chocolatey..." -ForegroundColor Cyan
if (!(Test-Path "$env:ProgramData\chocolatey")) {
    Write-Host ">>> Installing Chocolatey..." -ForegroundColor Cyan
    Set-ExecutionPolicy Bypass -Scope Process -Force
    [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
    Invoke-Expression ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
} else {
    Write-Host "Chocolatey is already installed. Skipping..." -ForegroundColor Yellow
}

Write-Host ">>> Installing MinGW-w64 (C++ compiler)..." -ForegroundColor Cyan
choco install mingw -y

Write-Host ">>> Installing Visual Studio Code..." -ForegroundColor Cyan
choco install vscode -y

Write-Host ">>> Configuring PATH environment variable..." -ForegroundColor Cyan
$mingwPath = "C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin"
$currentPath = [Environment]::GetEnvironmentVariable("Path", "Machine")
if ($currentPath -notlike "*$mingwPath*") {
    [Environment]::SetEnvironmentVariable("Path", "$currentPath;$mingwPath", "Machine")
    Write-Host "PATH updated. Please restart your terminal to apply changes." -ForegroundColor Green
} else {
    Write-Host "PATH already includes MinGW. Skipping..." -ForegroundColor Yellow
}

Write-Host ">>> Installing VSCode C++ extension..." -ForegroundColor Cyan
if (Get-Command code -ErrorAction SilentlyContinue) {
    code --install-extension ms-vscode.cpptools
} else {
    Write-Host "The 'code' command is not available. Please run it manually later:" -ForegroundColor Red
    Write-Host "code --install-extension ms-vscode.cpptools" -ForegroundColor Red
}

Write-Host ">>> Installation complete! Please restart your computer or sign out/in to apply PATH changes." -ForegroundColor Green
Pause