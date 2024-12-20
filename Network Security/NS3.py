def rail_fence_encrypt(text, key):
    rail = [['\n' for i in range(len(text))]
                  for j in range(key)]
   
    dir_down = False
    row, col = 0, 0
   
    for i in range(len(text)):
        if (row == 0) or (row == key - 1):
            dir_down = not dir_down
       
        rail[row][col] = text[i]
        col += 1
       
        if dir_down:
            row += 1
        else:
            row -= 1
           
    result = []
    for i in range(key):
        for j in range(len(text)):
            if rail[i][j] != '\n':
                result.append(rail[i][j])
               
    return("" . join(result))


def rail_fence_decrypt(cipher, key):
    rail = [['\n' for i in range(len(cipher))]
                  for j in range(key)]
   
    dir_down = None
    row, col = 0, 0
   
    for i in range(len(cipher)):
        if (row == 0) or (row == key - 1):
            dir_down = not dir_down
           
        rail[row][col] = '*'
        col += 1
       
        if dir_down:
            row += 1
        else:
            row -= 1
           
    index = 0
    for i in range(key):
        for j in range(len(cipher)):
            if ((rail[i][j] == '*') and
               (index < len(cipher))):
                rail[i][j] = cipher[index]
                index += 1
               
    result = []
    row, col = 0, 0
    for i in range(len(cipher)):
       
        if (row == 0) or (row == key - 1):
            dir_down = not dir_down
           
        if (rail[row][col] != '*'):
            result.append(rail[row][col])
            col += 1
           
        if dir_down:
            row += 1
        else:
            row -= 1
    return("" . join(result))


def read_file(filename):
    with open(filename, 'r') as file:
        return file.read()


def write_file(filename, content):
    with open(filename, 'w') as file:
        file.write(content)


if __name__ == "__main__":


    plaintext = read_file('Plaintext.txt')
    key = int(input("Enter the key value: "))
    ciphertext = rail_fence_encrypt(plaintext, key)
    write_file('Cipher.txt', ciphertext)
    ciphertext = read_file('Cipher.txt')
    decrypted_text = rail_fence_decrypt(ciphertext, key)
    write_file('Recover.txt', decrypted_text)
    print("all done")
