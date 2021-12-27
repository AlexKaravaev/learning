use std;

fn largest<T: std::cmp::PartialOrd>(list: &[T]) -> T where T:Copy{
    let mut largest = list[0];

    for &number in list{
        if number > largest{
            largest = number;
        }
    }

    largest
}


struct Point<T> {
    x: T,
    y: T,
}

enum Result<T,E> {
    Ok(T),
    Err(E),
}

impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }
}

impl Point<f32> {
    fn distance_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

fn main() {
    let number_list = vec![34, 50, 25, 100, 65];

    let largest_num: i32 = largest(&number_list);
    println!("The largest num is {}", largest_num);

    let integer = Point { x: 5, y: 10 };
    let float = Point { x: 1.0, y: 4.0 };

    println!("dist {}", float.distance_from_origin());
}
