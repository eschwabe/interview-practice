# Cracking the Coding Interview
# Problem 3.4

def move_disks(src, dest, tmp, n):
    if n == 0:
        return
    move_disks(src, tmp, dest, n-1)
    dest.append(src.pop())
    print_current()
    move_disks(tmp, dest, src, n-1)

def print_current():
    print src, dest, tmp

src = [4,3,2,1]
dest = []
tmp = []

print_current()
move_disks(src, dest, tmp, len(src))
