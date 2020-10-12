import statistics
def solution(A):
    try: mode = statistics.mode(A)
    except: return -1
    else: return A.index(mode) if A.count(mode) > int(len(A) / 2) else -1