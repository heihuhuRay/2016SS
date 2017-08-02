package Aspects;

import java.util.logging.Logger;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.reflect.MethodSignature;

/**
 * 
 * Implementation of the logging aspect.
 * 
 * In this example annotations are used. Other solutians are possible
 * 
 * @author mfrank
 *
 */
@Aspect
public class LoggingAspect {

	// defines the pointcuts. Means when to weave the code.
	// and defines the type in this case around. 
	@Around("execution(* *(..)) ")
	public Object around(ProceedingJoinPoint point) {
		
		// Printing the before the methode is called
		System.out.println("before: "+ MethodSignature.class.cast(point.getSignature()).getMethod().getName());
		Object result = null;
		
		// execute the actuale methode
		try {
			result = point.proceed();
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		// Printing the after the methode is called
		System.out.println("after: "+ MethodSignature.class.cast(point.getSignature()).getMethod().getName());

		return result;
	}
}
