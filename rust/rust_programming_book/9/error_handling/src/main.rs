use std::fs;
use std::fs::File;
use std::io::{ErrorKind, self, Read};

// Long func

fn read_username_from_file() -> Result<String, io::Error> {
    let f = File::open("hello.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();

    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}

// Shorter way with same functionality using propagating operator ?
fn read_username_from_file_short() -> Result<String, io::Error> {
    let mut f = File::open("hello.txt")?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)
}

fn read_username_from_file_shorter() -> Result<String, io::Error> {
    let mut s = String::new();

    File::open("hello.txt")?.read_to_string(&mut s)?;

    Ok(s)
}

fn read_username_from_file_even_shorter() -> Result<String, io::Error> {
    fs::read_to_string("hello.txt")
}

fn main() {

    println!("Hello, world!");

    // Outside the bounds

    //    let v = vec![1,2,3];
    //
    //    v[99];

    let f = File::open("hello.txt");

//    let f = match f {
//        Ok(file) => file,
//        Err(error) => match error.kind(){
//            ErrorKind::NotFound => match File::create("hello.txt") {
//                Ok(fc) => fc,
//                Err(e) => panic!("Problem creating the file: {:?}", e),
//            },
//            other_error => {
//                panic!("Problem file {:?}",error)
//            }
//        },
//    };

    // More RUSTY way


    let f = File::open("hello.txt").unwrap_or_else(|error| {
        if error.kind() == ErrorKind::NotFound {
            File::create("hello.txt").unwrap_or_else(|error| {
                panic!("Problem creating the file: {:?}", error);
            })
        } else {
            panic!("Problem opening the file: {:?}", error);
        }
    });

    // Unwrap returns content if all ok, or it panics if not
    let f = File::open("hello.txt").unwrap();

    // Expect similar to unwrap, but with panic message
    let f = File::open("hello.txt").expect("No such file hello.txt");

}
