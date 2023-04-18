/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        //see function length varies from 0 to 100 its not limited to 3
        for(let i=functions.length-1;i>=0;i--)
            {
               x=functions[i](x);   //f(x) 
            }
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */