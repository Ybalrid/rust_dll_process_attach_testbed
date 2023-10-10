#[no_mangle]
pub extern fn get_number() -> i32
{
    let mut var = 40;
    var += 2;
    return var;
}


#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        let result = crate::get_number();
        assert_eq!(result, 42);
    }
}

