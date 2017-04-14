f = open("BadRobots/BadRobots.html", "r")
contents = f.readlines()
f.close()

contents[13] = ".emscripten { padding-right: 0; display: block; }\n"
contents[1213] = "<div id=\"canvas_container\" class=\"emscripten_border\">\n"

contents.insert(len(contents) -2, "<script src=\"three.js\"></script>")

f = open("BadRobots/BadRobots.html", "w")
contents = "".join(contents)
f.write(contents)
f.close() 
