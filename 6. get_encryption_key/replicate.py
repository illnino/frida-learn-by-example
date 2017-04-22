from Crypto.Cipher import AES
from Crypto import Random
import requests

BS = 16
pad = lambda s: s + (BS - len(s) % BS) * chr(BS - len(s) % BS)
unpad = lambda s : s[0:-ord(s[-1])]

def decrypt(s, k):
    cipher = AES.new(k, AES.MODE_ECB)
    pt = cipher.decrypt(s)
    return unpad(pt)

def encrypt(s, k):
    cipher = AES.new(k, AES.MODE_ECB)
    ct = cipher.encrypt(pad(s))
    return ct

logink = "3246847986364861"
regk =   "9845674983296465"

def login(email, password):
    data = {
        'password': encrypt(password, logink).encode('base64').rstrip('\n'),
        'email': encrypt(email, logink).encode('base64').rstrip('\n')
    }
    return data
    

print login("test@gmail.com", "test")
