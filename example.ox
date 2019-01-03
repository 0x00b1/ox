module A {
    enumerated B {
        a
    };

    enumerated C {
        a,
        b
    };

    record D;

    record D {};

    record E {
        a: 16-bit Integer
    };

    record F {
        a: 16-bit Integer,
        b: 32-bit Integer
    };

    type G ← ⟨8-bit Integer × 8-bit Integer × 8-bit Integer⟩;

    type H ← [64 × 64 × 8-bit Integer];

    union I;

    union I {};

    union J {
        a: 32-bit Floating-point
    };

    union K {
        a: 16-bit Floating-point,
        b: 32-bit Floating-point
    };
};
