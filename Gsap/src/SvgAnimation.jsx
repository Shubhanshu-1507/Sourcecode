import React from 'react'
import { gsap } from 'gsap/gsap-core';
import {useGSAP} from '@gsap/react'


gsap.registerPlugin(useGSAP);

const SvgAnimation = () => {

    var path = "M 10 100 Q 500 100 990 100";
    var finalPath = "M 10 100 Q 500 100 990 100"; 

    const mouseEnter = (debs)=>{
        path = `M 10 100 Q 500 ${debs.clientY} 990 100`

       gsap.to('svg path',{
        attr:{d:path},
        scrub:1
       })
        console.log(debs)
        // console.log("mouse entered")
    }


    const mouseLeave = ()=>{
        console.log("mouse leaved")

        gsap.to('svg path', {
            attr: { d: finalPath }
        })
    }

  return (
    <>
    <div className="box1 border-2 border-white" >
              <svg width="1090" height="260" className='bg-teal-200  border-2 border-pink-200' xmlns="http://www.w3.org/2000/svg"
                  onMouseEnter={mouseEnter} onMouseLeave={mouseLeave}>
                  <path className='border-2 border-green-300' d="M 10 100 Q 500 100 990 100" stroke="black" fill="transparent" />
              </svg>
            <svg width="1090" height="1000" className='bg-slate-600'>
                <path d='M10 10 Q 100 100 100'/>

            </svg>

    </div>
    </>
  )
}

export default SvgAnimation



/* 
svg basic to advanced guide ->

svg is basically a container which consist a content and the svg contain path.

path-> 

it's an elemet of the svg which is used to create line ,curve and arc.
1. path create complex shapes  by combinng mutliple straight line or curve.
2. the shape  of the svg image  is based on only one parameter of the path element that is d.The d attribute contains a series of commands and parameters used by those commands.



path of the svg image: 
---> here the M denote the move to point like from where we have to start (starting  point).
---> now there are two type of curve in path that are quadratic curve and cubic curve.
---> the quadratic curve is denoted by Q and cubic curve is denoted by C.

---> this is how a quadraric curved is formed.
       l hhbgggQ x1 y1, x y
*/