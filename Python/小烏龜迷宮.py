# turtle_maze.py
import turtle

# 簡易迷宮格線
def draw_maze():
    grid = [
        "#####",
        "#   #",
        "# # #",
        "#   #",
        "#####"
    ]
    t = turtle.Turtle()
    t.speed(0)
    t.penup()
    for y, row in enumerate(grid):
        for x, ch in enumerate(row):
            if ch == '#':
                t.goto(-100 + x*40, 100 - y*40)
                t.pendown()
                t.begin_fill()
                for _ in range(4):
                    t.forward(40)
                    t.right(90)
                t.end_fill()
                t.penup()

def setup_player():
    player = turtle.Turtle("turtle")
    player.color("blue")
    player.penup()
    player.goto(-60, 60)
    return player

def move_up():
    player.setheading(90)
    player.forward(40)
def move_down():
    player.setheading(270)
    player.forward(40)
def move_left():
    player.setheading(180)
    player.forward(40)
def move_right():
    player.setheading(0)
    player.forward(40)

screen = turtle.Screen()
screen.title("小烏龜迷宮")
draw_maze()
player = setup_player()

screen.listen()
screen.onkey(move_up, "Up")
screen.onkey(move_down, "Down")
screen.onkey(move_left, "Left")
screen.onkey(move_right, "Right")

screen.mainloop()
