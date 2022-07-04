for val in [2, 2, 1, 0, 0, 3, 3]:
    print(f"? insert {val}", flush=True)
print("? remove", flush=True)
_ = int(input())
print("? remove", flush=True)
v = int(input())

m = {
    0: "pq",
    1: "set",
    2: "queue",
    3: "stack"
}

print(f"! {m[v]}", flush=True)
