use std::net::{Ipv4Addr, Ipv6Addr};
use std::str::FromStr;

struct IpAddr {
    v4: Ipv4Addr,
    v6: Ipv6Addr,
}

fn main() {
    let localhost = IpAddr{
        v4: Ipv4Addr::from_str("127.1.1.1").expect("Ip wrong"),
        v6: Ipv6Addr::from_str("::1").expect("Ip wrong")
    };

    let number: Option<i32> = Some(5);
    let number_none: Option<i32> = None;

    let int = 45;

    let sum = 45 + number.unwrap_or(0);

}
