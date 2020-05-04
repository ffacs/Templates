template<typename T>
struct Complex{
    T r,i;
    Complex(T r,T i):r(r),i(i){}
    inline void real ( const double& x )  {  r = x ;  }
	inline double real ( )  {  return r ;  }
	inline Complex operator + ( const Complex& rhs )  const  {
		return Complex ( r + rhs.r, i + rhs.i ) ;
	}
	inline Complex operator - ( const Complex& rhs )  const  {
		return Complex ( r - rhs.r, i - rhs.i ) ;
	}
	inline Complex operator * ( const Complex& rhs )  const  {
		return Complex ( r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r ) ;
	}
	inline void operator /= ( const double& x )   {
		r /= x, i /= x ;
	}
	inline void operator *= ( const Complex& rhs )   {
		*this = Complex ( r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r ) ;
	}
	inline void operator += ( const Complex& rhs )   {
		r += rhs.r, i += rhs.i ;
	}
	inline Complex conj ( )  {
		return Complex ( r, -i ) ;
	}
};
