import React, { Component } from 'react';
import styled from 'styled-components';

const SIZE = `80px`;
const LoaderWrapper = styled.div`
    display: inline-block;
    position: relative;
    width: ${SIZE};
    height: ${SIZE};
`;
const LoaderElement = styled.div`
    display: block;
    border-radius: 50%;
    width: 0;
    height: 0;
    margin: 8px;
    box-sizing: border-box;
    border: 32px solid #fff;
    border-color: #a64ed0 transparent #a64ed0 transparent;
    animation: lds-hourglass 1.2s infinite;

    @keyframes lds-hourglass {
        0% {
          transform: rotate(0);
          animation-timing-function: cubic-bezier(0.55, 0.055, 0.675, 0.19);
        }
        50% {
          transform: rotate(900deg);
          animation-timing-function: cubic-bezier(0.215, 0.61, 0.355, 1);
        }
        100% {
          transform: rotate(1800deg);
    }
`;

class Loader extends Component {
    render() {
        return (
            <LoaderWrapper>
                <LoaderElement />
            </LoaderWrapper>
        );
    }
}

export default Loader;
