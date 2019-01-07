constant a: 8-bit Integer ← 0;

enumeration A {

};

enumeration A {
    case a
};

enumeration A {
    case a
    case b
};

enumeration A {
    case a, b
};

enumeration A {
    case a ← 1, b
};

enumeration A⟨T⟩ {
    case a
    case b
};

record A {
    a: 8-bit Integer
};

record A {
    a: 8-bit Integer,
    b: 8-bit Integer
};

record A⟨T⟩ {
    a: T,
    b: T
};

union A {
    
};

union A {
    a: 8-bit Integer
};

union A {
    a: 8-bit Integer,
    b: 8-bit Integer
};

subroutine f → 8-bit Integer {
    return 0;
};

subroutine f() → 8-bit Integer {
    return 0;
};

subroutine f(x: 8-bit Integer) → 8-bit Integer {
    return x;
};

subroutine f′ → 8-bit Integer {
    return 0;
};

subroutine f′() → 8-bit Integer {
    return 0;
};

subroutine f′(x: 8-bit Integer) → 8-bit Integer {
    return x;
};

subroutine f {
    return;
};

subroutine f() {
    return;
};

subroutine f(x: 8-bit Integer) {
    return;
};

subroutine f(x: 8-bit Integer) → 8-bit Integer {
    if x = 0 {
        return x;
    }
};

subroutine f(x: 8-bit Integer) → 8-bit Integer {
    if x = 0 {
        return x;
    } else {
        return x + 1;
    }
};

subroutine f(x: 8-bit Integer) → A {
    return A {
        a: x
    };
};

subroutine example(x: 8-bit Integer) → f {
    return λ (y: 8-bit Integer) → 8-bit Integer {
        x + y
    };
};

subroutine example(x: 8-bit Integer) {
    for x in 1, … 100 {
        x + 1
    }

    for x in 1, 2, … 100 {
        x + 1
    }

    while x > 0 {
        x + 1
    }
};

type A ← ⟨8-bit Integer⟩;

type A ← ⟨8-bit Integer × 8-bit Integer × 8-bit Integer⟩;

type A ← [64 × 8-bit Integer];

type A ← [64 × 64 × 8-bit Integer];
