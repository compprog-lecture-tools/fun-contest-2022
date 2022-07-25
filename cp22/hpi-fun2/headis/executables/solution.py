import io, os
r = io.BytesIO(os.read(0, os.fstat(0).st_size))
r.readline()
print(r.readline().decode()[-2])
