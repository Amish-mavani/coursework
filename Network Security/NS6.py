import numpy as np
import math


def create_key_matrix(key):
    key_length = len(key)
    matrix_size = int(math.sqrt(key_length))


    key_matrix = []
    for i in range(matrix_size):
        row = [ord(char) % 65 for char in key[i * matrix_size:(i + 1) * matrix_size]]
        key_matrix.append(row)


    return np.array(key_matrix)


def create_plaintext_matrices(plaintext, matrix_size):


    plaintext = ''.join(filter(str.isalpha, plaintext)).upper()


    while len(plaintext) % matrix_size != 0:
        plaintext += 'X'


    plaintext_matrices = []
    for i in range(0, len(plaintext), matrix_size):
        block = plaintext[i:i + matrix_size]
        plaintext_matrix = [[ord(char) % 65] for char in block]
        plaintext_matrices.append(np.array(plaintext_matrix))


    return plaintext_matrices


def encrypt_hill_cipher(key_matrix, plaintext_matrices):
    encrypted_matrices = []


    for plaintext_matrix in plaintext_matrices:
        encrypted_matrix = np.dot(key_matrix, plaintext_matrix) % 26
        encrypted_matrices.append(encrypted_matrix)


    return encrypted_matrices


def mod_inverse_matrix(matrix, modulus):
    determinant = int(round(np.linalg.det(matrix)))
    determinant_inv = pow(determinant, -1, modulus)
    matrix_adj = np.round(determinant * np.linalg.inv(matrix)).astype(int)
    matrix_inv_mod = (determinant_inv * matrix_adj) % modulus
    return matrix_inv_mod


def decrypt_hill_cipher(key_matrix_inv, encrypted_matrices):
    decrypted_matrices = []


    for encrypted_matrix in encrypted_matrices:
        decrypted_matrix = np.dot(key_matrix_inv, encrypted_matrix) % 26
        decrypted_matrices.append(decrypted_matrix)


    return decrypted_matrices


def read_file(filename):
    with open(filename, 'r') as file:
        return file.read()


def write_file(filename, content):
    with open(filename, 'w') as file:
        file.write(content)


def matrix_to_text(matrix):
    return ''.join([chr(int(num) + 65) for num in matrix.flatten()])


if __name__ == "__main__":


    key = input("Enter the key (nxn): ").upper()


    plaintext = read_file("Plaintext.txt")


    key_matrix = create_key_matrix(key)
    matrix_size = key_matrix.shape[0]
    print("\nKey Matrix:")
    print(key_matrix)


    plaintext_matrices = create_plaintext_matrices(plaintext, matrix_size)
    print("\nPlaintext Matrices:")
    print("\n",np.array(plaintext_matrices).T)


    encrypted_matrices = encrypt_hill_cipher(key_matrix, plaintext_matrices)


    print("\nEncrypted Matrices:")
    print("\n",np.array(encrypted_matrices).T)


    encrypted_text = ''.join([matrix_to_text(matrix) for matrix in encrypted_matrices])
    write_file('Cipher.txt', encrypted_text)
    print("\nEncryption complete. Encrypted text saved to Cipher.txt.")


    try:
      key_matrix_inv = mod_inverse_matrix(key_matrix, 26)
      print("\nInverse Key Matrix :")
      print(key_matrix_inv)


      decrypted_matrices = decrypt_hill_cipher(key_matrix_inv, encrypted_matrices)


      print("\nDecrypted Matrices :")
      print(np.array(decrypted_matrices).T)


      decrypted_text = ''.join([matrix_to_text(matrix) for matrix in decrypted_matrices])
      write_file('Recover.txt', decrypted_text)
      print("\nDecryption complete. Encrypted text saved to Cipher.txt.")
    except ValueError as e:
        print("\n")
        print(e)
        print("\nDecryption incomplete")
    #GYBNQKURP
