fn first_word(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}

fn any_word(s: &String, word_num: u32) -> &str {
    let bytes = s.as_bytes();

    let mut cntr: u32 = 0;
    let mut prev_word_idx: usize = 0;

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' '{
            cntr += 1;
            if cntr == word_num{
                return &s[prev_word_idx..i];
            }
            prev_word_idx = i;
        }
    }

    &s[prev_word_idx..]
}

fn main() {
    let mut s = String::from("hello world yaw");

    let word = any_word(&s,3); // word will get the value 5

    println!("First word is {}", &word);
    s.clear(); // this empties the String, making it equal to ""

    // word still has the value 5 here, but there's no more string that
    // we could meaningfully use the value 5 with. word is now totally invalid!
}
