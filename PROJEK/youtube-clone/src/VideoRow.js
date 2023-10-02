import React from 'react';
import './VideoRow.css';

function VideoRow({views, subs, description, timestamp, channel, title, image}) {
  return (
    <div className='video_row'>
        <img src={image} alt=''/>
        <div className='video_row_text'>
            <h3>
                {title}
            </h3>
            <p className='video_row_headline'>
                {channel} • {" "}
                <span className='video_row_subs'> 
                        <span className='video_row_subs_num'>{subs} </span>
                    Subscriber 
                </span> {" "}
                {views} views • {timestamp}
            </p>
            <p className='video_row_desc'>
                {description}
            </p>
        </div>
        
    </div>
  )
}

export default VideoRow