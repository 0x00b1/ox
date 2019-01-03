module A {
    constant x: 8-bit Integer ← 0;

    enumerated A {
        a
    };

    enumerated A {
        a,
        b
    };

    record A;

    record A {};

    record A {
        a: 16-bit Integer
    };

    record A {
        a: 16-bit Integer,
        b: 32-bit Integer
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

    type A ← ⟨8-bit Integer⟩;

    type A ← ⟨8-bit Integer × 8-bit Integer × 8-bit Integer⟩;

    type A ← [64 × 8-bit Integer];

    type A ← [64 × 64 × 8-bit Integer];

    union A;

    union A {};

    union A {
        a: 32-bit Floating-point
    };

    union A {
        a: 16-bit Floating-point,
        b: 32-bit Floating-point
    };
};
