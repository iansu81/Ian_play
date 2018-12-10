from itertools import cycle

with open('input.txt') as f:
    content = f.readlines()
# you may also want to remove whitespace characters like `\n` at the end of each line
content = [x.strip() for x in content]
result = 0
dup = set()
dup.add(result)
for x in cycle(content):
    if x[0] == '+':
        add_val = int(x[1:])
    else:
        add_val = int(x)

    result = result + add_val
    if result in dup:
        print(result)
        break
    else:
        dup.add(result)
