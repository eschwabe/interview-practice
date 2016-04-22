#def products(inputs, num, index, outputs):
#    if index >= len(inputs):
#        return
#    tmp = num*inputs[index]
#    outputs.append(tmp)
#    products(inputs, num, index+1, outputs)
#    products(inputs, tmp, index+1, outputs)
#
#
#inputs = [3,11,2, 7,4,8]
#outputs = []
#
#products(inputs, 1, 0, outputs)
#
#print sorted(outputs)
#print len(outputs)

# Generate all products from a list of prime numbers

def products(input, num, index, output):
    if index > len(input):
        return
    output.append(num)
    for new_index in range(index+1, len(input)):
        products(input, num*input[new_index], new_index, output)

input = [2, 11, 3, 4, 7, 8]
output = []

for index in range(len(input)):
    products(input, input[index], index, output)

print sorted(output)
print len(output)

