 use core::fmt::Display;

pub trait Summary {
    fn summarize_author(&self) -> String {
        String::from("No author")
    }

    fn summarize(&self) -> String{
        String::from("(Read more...)")
    }
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}
//impl Summary for NewsArticle{
////    Here default impl will be called
//}

impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("{}, by {}, ({})", self.headline, self.author, self.location)
    }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }

    fn summarize_author(&self) -> String {
        format!("@{}", self.username)
    }

}

pub fn notify(item: &impl Summary) {
    println!("Breaking news! {}", item.summarize());
}

// They are the same , but below is what called a trait bound
//pub fn notify<T: Summary>(item: &T){
//    println!("Breaking news! {}", item.summarize());
//}
//
//// Examples of multiple traits
//pub fn notify(item: &(impl Summary + Display)) {
//
//}
//
//pub fn notify<T: Summary + Display>(item: &T) {
//
//}

// Also where is an option
//fn some_function<T, U>(t: &T, u: &U) -> i32
//    where T: Display + Clone,
//          U: Clone + Debug
//{
//
//}