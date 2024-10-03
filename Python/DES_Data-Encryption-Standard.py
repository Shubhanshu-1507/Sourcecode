from Crypto.Cipher import DES

def des_encrypt(key, data):
    cipher = DES.new(key, DES.MODE_ECB)
    return cipher.encrypt(data)

def des_decrypt(key, ciphertext):
    cipher = DES.new(key, DES.MODE_ECB)
    return cipher.decrypt(ciphertext)

key = b'8bytekey'  # DES key must be 8 bytes long
data = b'8byteblk'  # Data must be a multiple of 8 bytes
ciphertext = des_encrypt(key, data)
print(f"Ciphertext: {ciphertext}")
print(f"Decrypted: {des_decrypt(key, ciphertext)}")
