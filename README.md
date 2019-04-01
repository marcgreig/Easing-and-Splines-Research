# Easing and Splines Research

## Easing

Easing functions allow to apply mathematical formulas like splines to certain animations in order to diminish the amount of work required for each animation which means that the function itself describes the movement instead of hardcoding it for each animation. Also, by giving the animation certain acceleration it allows the coder to achieve a much more smooth result. 
In the case of a camera, instead of coding the amount of distance it needs to travel each frame it gives the camera a speed depending on the distance from his objective position.

Each easing function depends on four parameters:
- Current time (t) which is the moment where the object is.
- Beggining value (b) which the position where the object is at the moment t.
- Change in value (c) which is the difference of value between the current position and the final position.
- Duration (d) which is the total number of iterations that you want your animation to have, needs to be the current unit as the starting time.

There are different types of easing functions, five standard classes and some other more complex.

The six standard classes use a power that ranges from 1 to 5:
- Linear using a power of 1, which means that at 20% of the tween the object will be at the 20 % of distance.
- Quad using a power of 2, which means that the value would increase by a power of 2.
- Cubic using a power of 3.
- Quard using a power of 4.
- Quint, also called Strong, using a power of 5.
- Circular using a power of 6.
The more the power of the function the faster it will increase its speed.

The other more complex classes apply a different Math method are:
- Sinusoidal applying the mathematical cosine and sine methods
- Exponential is similar to the standar classes but instead of using a power it increases/decreases exponentially to the inital value.
- Elastic tries to imitate the movement of a string where it accelerates and deaccelerates smoothly.
- Back allows the object to bypass the objective and then return as if there were a reverse gravity.
- Bounce tries to imitate the movement of a bouncing ball, for example, applying an acceleration and deacceleration similar to the gravity would.

The following graphs will representate their movement:
