input_length  = int(input())
words = []

for index in range(input_length) :
    words.append(input())


words = sorted(words, key=lambda x : (len(x), x))

before = "-1"
for word in words :
    if before == word :
        continue
    print(word)
    before = word

    