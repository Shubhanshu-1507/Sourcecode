import hmac
import hashlib

def create_hmac(key, message):
    return hmac.new(key.encode(), message.encode(), hashlib.sha256).hexdigest()

key = "supersecretkey"
message = "Important message"
mac = create_hmac(key, message)
print(f"HMAC: {mac}")
