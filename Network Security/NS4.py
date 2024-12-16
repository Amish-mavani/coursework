import re


def generate_table(key):
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    table = []
    used_chars = set()


    filtered_key = re.sub(r'[^A-Za-z0-9]', '', key.upper())


    for char in filtered_key:
        if char not in used_chars:
            table.append(char)
            used_chars.add(char)


    for char in alphabet:
        if char not in used_chars:
            table.append(char)
            used_chars.add(char)


    print("\n")
    print([table[i:i+6] for i in range(0, 36, 6)])
    print("\n")
    return [table[i:i+6] for i in range(0, 36, 6)]


def find_position(table, char):
    for i, row in enumerate(table):
        if char in row:
            return i, row.index(char)


def encrypt_playfair(plaintext, table):
   
    plaintext = re.sub(r'[^A-Za-z0-9]', '', plaintext.upper())  
    pairs = []
    i = 0
    while i < len(plaintext):
        a = plaintext[i]
        if i + 1 < len(plaintext) and plaintext[i + 1] != a:
            b = plaintext[i + 1]
            i += 2
        else:
            b = 'X'  
            i += 1
        pairs.append((a, b))


    encrypted_text = []
    for a, b in pairs:
        row_a, col_a = find_position(table, a)
        row_b, col_b = find_position(table, b)


        if row_a == row_b:
            encrypted_text.append(table[row_a][(col_a + 1) % 6])
            encrypted_text.append(table[row_b][(col_b + 1) % 6])
        elif col_a == col_b:
            encrypted_text.append(table[(row_a + 1) % 6][col_a])
            encrypted_text.append(table[(row_b + 1) % 6][col_b])
        else:
            encrypted_text.append(table[row_a][col_b])
            encrypted_text.append(table[row_b][col_a])


    return ''.join(encrypted_text)


def decrypt_playfair(ciphertext, table):
    pairs = [(ciphertext[i], ciphertext[i + 1]) for i in range(0, len(ciphertext), 2)]
    decrypted_text = []


    for a, b in pairs:
        row_a, col_a = find_position(table, a)
        row_b, col_b = find_position(table, b)


        if row_a == row_b:          
            decrypted_text.append(table[row_a][(col_a - 1) % 6])
            decrypted_text.append(table[row_b][(col_b - 1) % 6])
        elif col_a == col_b:          
            decrypted_text.append(table[(row_a - 1) % 6][col_a])
            decrypted_text.append(table[(row_b - 1) % 6][col_b])
        else:
            decrypted_text.append(table[row_a][col_b])
            decrypted_text.append(table[row_b][col_a])


    return ''.join(decrypted_text)


def read_file(filename):
    with open(filename, 'r') as file:
        return file.read()


def write_file(filename, content):
    with open(filename, 'w') as file:
        file.write(content)




if __name__ == "__main__":
       
        print("\nPlayfair Cipher")
        print("1. to Encrypt")
        print("2. to Decrypt")


        key = input("Enter the encryption key: ")
        table = generate_table(key)
        plaintext = read_file('Plaintext.txt')
        encrypted_text = encrypt_playfair(plaintext, table)
        write_file('Cipher.txt', encrypted_text)
        print("Encryption complete. Encrypted text saved to Cipher.txt.")


        key = input("Enter the decryption key: ")
        table = generate_table(key)
        ciphertext = read_file('Cipher.txt')
        decrypted_text = decrypt_playfair(ciphertext, table)
        write_file('Recover.txt', decrypted_text)
        print("Decryption complete. Decrypted text saved to Recover.txt.")
        print("all done")
