#[derive(Debug)]
struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool
}

impl User {
    fn increase_sign_in_count(&mut self){
        self.sign_in_count += 1;
    }
}
fn build_user(email: String, username: String) -> User{
    User{
        email: email,
        username: username,
        active: true,
        sign_in_count: 1
    }
}
fn main() {
    let mut user = User{
        username: String::from("Alex"),
        email: String::from("test@mail.com"),
        sign_in_count: 0,
        active: true
    };

    let _name = user.username;

    user.username = String::from("Tom");

    let _user2 = build_user(String::from("Test"),String::from("test2@mail.com"));

    println!("{:?}", user);

    user.increase_sign_in_count();

    println!("{:?}", user);


}
