import urllib.parse as u
import base64 as b


data="JTYzJTMwJTZlJTc2JTMzJTcyJTc0JTMxJTZlJTY3JTVmJTY2JTcyJTMwJTZkJTVmJTYyJTYxJTM1JTY1JTVmJTM2JTM0JTVmJTMwJTYyJTM5JTM1JTM3JTYzJTM0JTY2"
bytes = data.encode('utf-8')
base = b.b64decode(bytes)
base = base.decode("utf-8")
flag = u.unquote(base)
print("picoCTF{"+flag+"}")