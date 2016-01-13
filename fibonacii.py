
def fibonacii(n):
    if n == 0:
        return 0
    if n == 1:
        return 1

    return (fibonacii(n - 1) + fibonacii(n - 2));

print fibonacii(6)

