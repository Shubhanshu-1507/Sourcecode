from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Random import get_random_bytes

def rsa_generate_keys():
    key = RSA.generate(2048)
    private_key = key.export_key()
    public_key = key.publickey().export_key()
    return private_key, public_key

def rsa_encrypt(public_key, data):
    recipient_key = RSA.import_key(public_key)
    cipher_rsa = PKCS1_OAEP.new(recipient_key)
    return cipher_rsa.encrypt(data.encode('utf-8'))

def rsa_decrypt(private_key, ciphertext):
    private_key = RSA.import_key(private_key)
    cipher_rsa = PKCS1_OAEP.new(private_key)
    return cipher_rsa.decrypt(ciphertext).decode('utf-8')

private_key, public_key = rsa_generate_keys()
ciphertext = rsa_encrypt(public_key, "Confidential Message")
print(f"Ciphertext: {ciphertext}")
print(f"Decrypted: {rsa_decrypt(private_key, ciphertext)}")
