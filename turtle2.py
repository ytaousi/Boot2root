import turtle 


def gogoTurtle(contents):
    lineNumber = 1
    for i in contents:
        if "Avance" in i:
            pen.forward()
        if "Recule" in i:
            print("found" + str(lineNumber))
        if "Tourne droite" in i:
            print("found" + str(lineNumber))
        if "Tourne gauche" in i:
            print("found" + str(lineNumber))
        lineNumber += 1
        # if i == "Avance":
        #     pen.forward()
        # if i == "Recule":
        #     pen.backward()
        # if i == "Tourne droite":
        #     pen.right()
        # if i == "Tourne gauche":
        #     pen.left()
with open("turtle.txt") as f:
    contents = f.readlines()

# Forming the window screen
tut = turtle.Screen()
tut.bgcolor("green")
tut.title("Turtle")

pen = turtle.Turtle()
pen.color("orange")

gogoTurtle(contents)
# tut = turtle.Screen()		 

# # for different shapes
# side = 300
# for i in range(10):
# 	form_tri(side)
# 	side -= 30

# Avance : 733

# Recule : 4

# Tourne droite : 366

# Tourne gauche : 362