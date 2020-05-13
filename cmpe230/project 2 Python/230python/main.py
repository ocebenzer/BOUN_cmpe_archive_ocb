from data import *
from variable import *
import re

fileName = "input.txt"
with open(fileName) as f:
    output = "counter= 0\n"
    for line in f.readlines():
        try:
            line = line[:line.index("#")]
        except ValueError:  # means there is no # in the line
            pass
        if line[-1:] == "\n":
            line = line[:-1]
        tokens = re.split("[\ \{\}\[\]\,\(\)\:]+", line)
        for e in tokens:
            if e == "":
                tokens.remove(e)
            for char in e:
                pass
        if tokens[0].startswith("scalar"):
            # if tokens.__len__!= 2: ERROR
            output += str(tokens[1] + "=scalar(\"" + tokens[1] + "\")\n")
        elif tokens[0].startswith("vector"):
            # if tokens.__len__!= 2: ERROR
            output += str(tokens[1] + "=vector(\"" + tokens[1] + "\"," + tokens[2] + ")\n")
        elif tokens[0].startswith("matrix"):
            # if tokens.__len__!= 2: ERROR
            output += str(tokens[1] + "=matrix(\"" + tokens[1] + "\"," + tokens[2] + "," + tokens[3] + ")\n")
        elif tokens[0].startswith("printsep"):
            output += "print \"----------\"\n"
        elif tokens[0].startswith("print"):
            if len(tokens) == 2:
                output += str("myprint(" + tokens[1] + ")\n")
            elif len(tokens) == 3:
                output += str("myprint(" + tokens[1] + "," + tokens[2] + ")\n")
            else:
                pass  # syntax error
        elif tokens[0].startswith("for"):
            pass  # TODO
        elif tokens[0].startswith("tr"):
            pass  # TODO
        elif tokens[0].startswith(("sqrt")):
            pass  # TODO
        elif tokens[0].startswith("choose"):
            pass  # TODO
        else:
            if tokens[1] == "=":
                output += "fill(" + tokens[0] + ", " + str(tokens[2:]) + ")\n"
            elif tokens[1] == "+":
                pass # TODO
            elif tokens[1] == "-":
                pass #TODO
            elif tokens[1] == "*":
                pass # TODO, good luck
            else:
                pass #  syntax error

print output
print "---lets begin---"
exec (output)
print "done"
