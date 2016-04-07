# Cracking The Coding Interview
# Problem 11.2

def sort_anagrams(strings):
  return sorted(strings,cmp=anasort)
  
def anasort(a,b):
  al = sorted(a)
  bl = sorted(b)
  if al < bl:
    return -1
  elif al > bl:
    return 1
  else:
    return 0

strs = ['god', 'asdf', 'dog', 'asfd', 'asdflkjf', 'more', 'fas']
strs_sorted = sort_anagrams(strs)
print strs
print strs_sorted