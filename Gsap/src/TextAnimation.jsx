import React from 'react'
import { gsap } from 'gsap/gsap-core';
import { useGSAP } from '@gsap/react';

const TextAnimation = () => {
  
    gsap.registerPlugin(useGSAP);

    useGSAP(()=>{
        gsap.to('h1',{
            duration: 2,
            delay:0.5,
            y:50,
            x:400,
            opacity:0.3
        })

        //from is nothing but just vice versa of the to mean whatever is happen in to the totaly oppsite happen in from

        gsap.from(".text",{
            delay:1,
            duration:3,
            opacity:0,
            y:-100,
            stagger:2, //use when you have to apply the animation one after other on the element
            

        })
    })
  return (
    <>

      <h4 className='text-center my-10 text-3xl uppercase'> text animation of gsap</h4>
          <h1 className='text-lg font-semibold' >this is the tutorial of GSAP</h1>
        <h1 className='text-lg font-semibold' >gsap is ananimation library</h1>
        <h1 className='text-lg font-semibold'>we can create multiple animation using that</h1>

        <h2 className='my-16 text-2xl capitalize'>for property of the gsap</h2>

        <h3 className='text my-2 text-lg font-bold capitalize'>Lorem ipsum dolor sit amet consectetur adipisicing elit. Odit dolorem rerum repudiandae?</h3>
      <h3 className='text my-2 text-lg font-bold capitalize'>Lorem ipsum dolor sit, amet consectetur adipisicing elit. Doloremque nobis aut quos consectetur voluptas.</h3>
      <h3 className='text my-2 text-lg font-bold capitalize'>Lorem ipsum dolor sit amet consectetur adipisicing elit. Aliquam maxime quidem adipisci deserunt nobis itaque aspernatur!</h3>

    </>
  )
}

export default TextAnimation