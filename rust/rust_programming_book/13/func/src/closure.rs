use std::thread;
use std::time::Duration;
use std::collections::HashMap;

struct Cacher<T>
where
    T: Fn(u32) -> u32,
{
    calculation: T,
    calculated: HashMap<u32, u32>,
}

impl<T> Cacher<T>
where
    T: Fn(u32) -> u32,
{
    fn new(calculation: T) -> Cacher<T> {
        Cacher {
            calculation,
            calculated: HashMap::new()
        }
    }

    fn value(&mut self, arg: u32) -> u32 {
        match self.calculated.get(&arg) {
            Some(v) => *self.calculated.get(v).unwrap(),
            None => {
                let v = (self.calculation)(arg);
                self.calculated.insert(arg, v);
                v
            }
        }
    }
}

#[test]
fn call_with_different_values() {
        let mut c = Cacher::new(|a| a);

        let v1 = c.value(1);
        let v2 = c.value(2);

        assert_eq!(v2, 2);
    }


fn simulated_expensive_calculation(intensity: u32) -> u32 {
    println!("calculating slowly");
    thread::sleep(Duration::from_secs(2));
    intensity
}

fn generate_workout(intensity: u32, random_number: u32) {

    let mut expensive_result = Cacher::new(|num| {
        println!("calculating slowly...");
        thread::sleep(Duration::from_secs(2));
        num
    });

    if intensity < 25{
        println!("Today do {} pushups",
         expensive_result.value(intensity));
        println!("Next do {} situps!",
         expensive_result.value(intensity));
    } else {

        if random_number == 3 {
            println!("Take a break today!");
        } else {
            println!(
                    "Today run for {} minutes",
             expensive_result.value(intensity));
        }
    }
}
fn main() {
    let simulated_user_value = 10;
    let simulated_random_number = 7;

    generate_workout(simulated_user_value, simulated_random_number);
}
