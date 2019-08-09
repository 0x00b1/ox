BinarySearch(A[0..N-1], value, low, high) {
    // invariants: value > A[i] for all i < low
                    value < A[i] for all i > high
    if (high < low)
        return not_found // value would be inserted at index "low"
    mid = (low + high) / 2
    if (A[mid] > value)
        return BinarySearch(A, value, low, mid-1)
    else if (A[mid] < value)
        return BinarySearch(A, value, mid+1, high)
    else
        return mid
}
