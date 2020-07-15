import os
import argparse



if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("path", help="display the directory:")
    args = parser.parse_args()
    print(args.path)
    ans = []
    for file in os.listdir(args.path):
        if file.startswith("A"):
            if file.endswith(".gps"):
            # print(file)
                ans.append(file)


# print(ans)
return ans