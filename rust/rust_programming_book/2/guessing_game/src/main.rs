use std::io;
use std::cmp::Ordering;
use rand::Rng;
use colored::*;

fn main() {
    println!("Input number ");

    let secret = rand::thread_rng().gen_range(1..101);

    println!("Guess the number! It's {} ;)", secret);




    loop {
        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You guessed: {}", guess);

        match guess.cmp(&secret) {
            Ordering::Less => println!("{}", "Too small!".red()),
            Ordering::Greater => println!("{}","Too big!".red()),
            Ordering::Equal => {
                println!("{}", "You win!".green());
                break;
            },
        }
    }
}
