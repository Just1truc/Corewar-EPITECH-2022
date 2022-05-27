import os
import subprocess
from os import path

path_to_champions = './champions/'
path_to_bin = './bin/'

if __name__ == '__main__':
    print("Calculating...")
    if (not(path.exists(path_to_champions) and path.isdir(path_to_champions)) or not(path.exists(path_to_bin) and path.isdir(path_to_bin))):
        print("bin folder of champions folder not found")
    champions_list = os.listdir(path_to_champions)
    champions_wins = {}
    for champion in champions_list:
        if (champion.endswith(".s")):
            continue
        if (not(champion in champions_wins)):
            champions_wins[champion] = 0
        for opposant in champions_list:
            if champion == opposant or opposant.endswith(".s"):
                continue
            print(f"== {champion} vs {opposant} ==")
            process = subprocess.Popen([path_to_bin + "corewar", path_to_champions + champion, path_to_champions + opposant ], stdout=subprocess.PIPE).communicate()[0]
            print(str(process).split("\\n")[-2])
            if ("1(" in str(process).split("\\n")[-2]):
                champions_wins[champion] += 1
            else:
                if (opposant in champions_wins):
                    champions_wins[opposant] += 1
                else:
                    champions_wins[opposant] = 1

    print("==== Results ====")
    for infos in reversed(sorted(champions_wins.items(), key=lambda t: t[1])):
        print(infos[0] + ": " + str(infos[1]))
    print("=================")

        
            
    