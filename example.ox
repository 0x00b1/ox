constant a ← 0;

enumeration A {
    a
};

enumeration A {
    a,
    b
};

enumeration A {
    a ← 1, b
};

enumeration A ⟨T⟩ {
    a,
    b
};

record A {
    a: 8-bit Integer
};

record A {
    a: 8-bit Integer,
    b: 8-bit Integer
};

record A ⟨T⟩ {
    a: T,
    b: T
};

union A {};

union A {
    a: 8-bit Integer
};

union A {
    a: 8-bit Integer,
    b: 8-bit Integer
};

union A ⟨T⟩ {
    a: T,
    b: T
};

subroutine f() → 8-bit Integer {};

subroutine f⟨T⟩() → T {};

subroutine f(x: 8-bit Integer) → 8-bit Integer {};

subroutine f⟨T⟩(x: T) → T {};

subroutine f(x: 8-bit Integer ← 0) → 8-bit Integer {};

subroutine f⟨T⟩(x: T ← 0) → T {};

subroutine f() {};

subroutine f(x: 8-bit Integer) {};

subroutine f⟨T⟩(x: T) {};

type A ← ⟨8-bit Integer × 8-bit Integer⟩;

type A ← [64 8-bit Integer];

type A ← [64 × 64 8-bit Integer];

type A ← [64 × 64 × 64 8-bit Integer];

for a in A {

};

if a {

};

if a {

} else {

};

if a {

} else if b {

} else {

};

while a {

};

switch a {};

switch a {
    case 1: 1;
};

switch a {
    case 1: 1;
    case 2: 2;
};

a ← 0;

[];

[1];

[1, 2, 3];

⟨1, 2⟩;

⟨1, 2, 3⟩;

⟨a: 1, b: 2, c: 3⟩;

a;

(a);

f();

f(1, 2, 3);

f(x: a, y: b);

A[0];

A[0, 0];

A[a];

A[a, b, c];

a is T;

a as T;

λ (x: T) → T {};

λ (x: T) {};

λ (x: T) → T { x; };

λ (x: T) { x; };

λ {};

λ { x; };

λ () {};

λ (x: T …) { x; };

_;
