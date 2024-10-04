import hashlib

def md5_hash(data):
    return hashlib.md5(data.encode('utf-8')).hexdigest()

print(md5_hash("Hello, World!"))
