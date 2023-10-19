import turtle
import time


def gogoTurtle(contents):
    for i in contents:
        if "Avance" in i:
            steps = [int(word) for word in i.split() if word.isdigit()]
            pen.forward(int(steps[0]))
        if "Recule" in i:
            steps = [int(word) for word in i.split() if word.isdigit()]
            pen.back(int(steps[0]))
        if "Tourne droite" in i:
            angle = [int(word) for word in i.split() if word.isdigit()]
            pen.right(int(angle[0]))
        if "Tourne gauche" in i:
            angle = [int(word) for word in i.split() if word.isdigit()]
            pen.left(int(angle[0]))

with open("letter.txt") as f:
    contents = f.readlines()

# Forming the window screen
tut = turtle.Screen()
tut.bgcolor("green")
tut.title("Turtle")

pen = turtle.Turtle()
pen.color("orange")


gogoTurtle(contents)
time.sleep(300)
# tut = turtle.Screen()		 


# Avance : 733

# Recule : 4

# Tourne droite : 366

# Tourne gauche : 362