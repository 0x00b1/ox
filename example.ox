module A {
    enumerated A {
        a
    };

    enumerated B {
        a,
        b
    };

    record C {};

    record D {
        a: 16-bit Integer
    };

    record E {
        a: 16-bit Integer,
        b: 32-bit Integer
    };

    type F ← ⟨8-bit Integer × 8-bit Integer × 8-bit Integer⟩;
    
    type G ← [224 × 224 × 3 × 8-bit Integer];
    
    /*
     * FIXME:
     * type G ← [224 × 224 × 3 × 8-bit Integer];
     */

    union H {};

    union I {
        a: 32-bit Floating-point
    };

    union J {
        a: 16-bit Floating-point,
        b: 32-bit Floating-point
    };
};
