
use std::collections::HashMap;

enum SpreadsheetCell {
    Int(i32),
    Float(f64),
    Text(String),
}

fn main() {
    let a = [1,2,3];
    let mut v: Vec<i32>  = Vec::new();

    v.push(2);

    {
        let v2 = vec![1, 2, 3];
    }
    // v2 goes out of scope and being dead

    let third = &v[0];

    match v.get(20) {
        Some(twenty_elem) => println!("The 20th elem is {}", twenty_elem),
        None => println!("No 20th elem in vec v"),
    };

    let row = vec![
        SpreadsheetCell::Float(10.22),
        SpreadsheetCell::Float(10.22),
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Text(String::from("blue")),
        SpreadsheetCell::Float(10.22),
    ];

    match &row[1] {
        SpreadsheetCell::Float(i) => println!("Float {}", i),
        _ => println!("Not a float"),
    };

    let blue = String::from("blue");
    let yellow = String::from("Yellow");

    let mut scores = HashMap::new();

    scores.insert(blue, 10);
    scores.insert(yellow, 20);

    match scores.get(&String::from("blue")) {
        Some(&score) => println!("score for blue: {}", score),
        _ => println!("No such team"),
    };


}
