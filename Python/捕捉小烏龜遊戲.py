# catch_turtle.py
import turtle
import random
import time

screen = turtle.Screen()
screen.title("捕捉小烏龜遊戲")
t = turtle.Turtle("turtle")
t.penup()

score = 0
start = time.time()

def move_turtle():
    t.goto(random.randint(-200,200), random.randint(-200,200))
    screen.ontimer(move_turtle, 1000)

def catch(x, y):
    global score
    if t.distance(x, y) < 20:
        score += 1
        print("得分！當前分數：", score)

move_turtle()
screen.onclick(catch)
screen.mainloop()

end = time.time()
print("遊戲時間：", int(end - start), "秒，總分：", score)
