from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric.utils import encode_dss_signature

# Generate an ECC private key
private_key = ec.generate_private_key(ec.SECP256R1())
public_key = private_key.public_key()

# Sign data
data = b"Message to sign"
signature = private_key.sign(data, ec.ECDSA(hashes.SHA256()))

# Verify signature
public_key.verify(signature, data, ec.ECDSA(hashes.SHA256()))
print("Signature is valid")
