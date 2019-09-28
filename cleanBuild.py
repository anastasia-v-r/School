import os, time, shutil

def chopafter(path):
    words = path.split("\\out\\")
    word = words[0]
    if (word.endswith('\\out\\')):
        #print("Cutting 5")
        word = word[:-5]
        #print(word)
    elif (word.endswith('\\out')):
        #print("Cutting 4")
        word = word[:-4]
        #print(word)
    #else:
        #print("Cutting None")
        #print(word)
    #print()
    return word

def list_files(startpath):
    for root, dirs, files in os.walk(startpath):
        level = root.replace(startpath, '').count(os.sep)
        indent = ' ' * 4 * (level)
        print('{}{}/'.format(indent, os.path.basename(root)))
        subindent = ' ' * 4 * (level + 1)
        for f in files:
            print('{}{}'.format(subindent, f))

def walkDir(folder, list_of_dirs):
    for subdir, dirs, files in os.walk(folder):
        if ("\\out\\" in subdir):
            out = chopafter(subdir)
            out = out + "\\out\\"
            if (out in list_of_dirs):
                #print("already exists")
                pass
            else:
                #print("adding dir")
                #print(out)
                #list_files(out)
                list_of_dirs.append(out)

cpp1 = os.getcwd() + "/GTC CPP 1/"
cpp2 = os.getcwd() + "/GTC CPP 2/"
cppT = os.getcwd() + "/GTC CPP TxtBk/"

dir_list = []
walkDir(cpp1, dir_list)
for folder in dir_list:
    shutil.rmtree(folder)

dir_list = []
walkDir(cpp2, dir_list)
for folder in dir_list:
    shutil.rmtree(folder)

dir_list = []
walkDir(cppT, dir_list)
for folder in dir_list:
    shutil.rmtree(folder)