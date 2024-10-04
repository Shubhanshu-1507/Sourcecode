from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

def aes_encrypt(key, data):
    cipher = AES.new(key, AES.MODE_EAX)
    nonce = cipher.nonce
    ciphertext, tag = cipher.encrypt_and_digest(data.encode('utf-8'))
    return nonce, ciphertext, tag

def aes_decrypt(key, nonce, ciphertext, tag):
    cipher = AES.new(key, AES.MODE_EAX, nonce=nonce)
    data = cipher.decrypt_and_verify(ciphertext, tag)
    return data.decode('utf-8')

key = get_random_bytes(16)  # AES-128 key
nonce, ciphertext, tag = aes_encrypt(key, "Secret Message")
print(f"Ciphertext: {ciphertext}")
print(f"Decrypted: {aes_decrypt(key, nonce, ciphertext, tag)}")
