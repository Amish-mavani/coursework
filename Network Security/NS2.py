import string
from collections import Counter


def caesar_encrypt(text, shift):
    result = ""
    for i in range(len(text)):
        char = text[i]
       
        if char.isupper():
            result += chr((ord(char) + shift - 65) % 26 + 65)
        elif char.islower():
            result += chr((ord(char) + shift - 97) % 26 + 97)
        elif char.isdigit():
            result += str((int(char) + shift) % 10)
        else:  
            result += char
           
    return result




def caesar_decrypt(text, shift):
    return caesar_encrypt(text, -shift)




def caesar_brute_force(ciphertext):
    possibilities = []
    for shift in range(26):
        decrypted_text = caesar_decrypt(ciphertext, shift)
        possibilities.append(f"Shift {shift}: {decrypted_text}\n")
        possibilities.append("\n")
    return "".join(possibilities)




def frequency_analysis(ciphertext):
    frequencies = Counter([char for char in ciphertext.lower() if char in string.ascii_lowercase])
    frequencies = frequencies.most_common()
    analysis = "Character Frequency Analysis:\n"
    for char, freq in frequencies:
        analysis += f"{char}: {freq}\n"
    return analysis




def read_file(filename):
    with open(filename, 'r') as file:
        return file.read()




def write_file(filename, content):
    with open(filename, 'w') as file:
        file.write(content)
 
       
if __name__ == "__main__":
 
        plaintext = read_file('Plaintext.txt')
        shift = int(input("Enter the shift value: "))
        ciphertext = caesar_encrypt(plaintext, shift)
        write_file('Cipher.txt', ciphertext)
       
        ciphertext = read_file('Cipher.txt')
        decrypted_text = caesar_decrypt(ciphertext, shift)
        write_file('Recover.txt', decrypted_text)
       
        possibilities = caesar_brute_force(ciphertext)
        write_file('Recover1.txt', possibilities)
       
        analysis = frequency_analysis(ciphertext)
        write_file('Recover2.txt', analysis)
        print("all done")
