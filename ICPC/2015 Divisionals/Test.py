import os
for file in os.listdir("keep/data/secret"):
    name, ext = file.split('.')
    if ext == "in":
        os.system("python K-tim.py < keep/data/secret/" + file + "> sample"+name+".out")
            
# os.system("python K.py < /keep/data/secret"
