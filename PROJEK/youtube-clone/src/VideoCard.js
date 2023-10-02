import { Avatar } from '@mui/material'
import React from 'react';
import './VideoCard.css';

function VideoCard( {image, title, channel, views, timestamp, channel_image} ) {
  return (
    <div className='video_card'>
        <img className='video_card_thumbnail' src={image} alt=''/>
        <div className='video_card_info'>
            <Avatar 
                className='video_card_avatar' 
                alt={channel} 
                src={channel_image} />
            
            <div className='video_card_text'>
                <h4> {title} </h4>
                <p> {channel} </p>
                <p> {views} • {timestamp} </p>
            </div>
        </div>
    </div>
  )
}

export default VideoCard