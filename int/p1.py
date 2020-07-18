import os
import argparse



def main():
    # Parse the command line arument
    parser = argparse.ArgumentParser()
    parser.add_argument("path", help="display the directory:")
    args = parser.parse_args()

    ans = []
    for file in os.listdir(args.path):
        # Filter the file name
        if file.startswith("A"):
            if file.endswith(".gps"):
                ans.append(file)

    return(ans)




if __name__ == '__main__':
    main()
    
   